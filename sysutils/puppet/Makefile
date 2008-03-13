# $NetBSD: Makefile,v 1.1.1.1 2008/03/13 14:17:05 tonnerre Exp $
#

DISTNAME=		puppet-0.22.4
CATEGORIES=		sysutils
MASTER_SITES=		http://www.reductivelabs.com/downloads/puppet/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.reductivelabs.com/projects/puppet/
COMMENT=		Configuration management framework written in Ruby

NO_BUILD=		yes
DOCS=			CHANGELOG TODO README LICENSE COPYING
PUPPET_DOCSDIR=		${PREFIX}/share/doc/puppet
PUPPET_EXAMPLESDIR=	${PREFIX}/share/examples/puppet
EXAMPLEROOT_DIRS=	bin etc etc/init.d etc/puppet
EXAMPLEROOT_FILES=	bin/sleeper etc/init.d/sleeper			\
	etc/puppet/puppetd.conf etc/puppet/fileserver.conf		\
	etc/puppet/puppetmasterd.conf etc/puppet/namespaceauth.conf	\
	etc/puppet/tagmail.conf etc/otherfile etc/configfile		\
	etc/debian-passwd etc/debian-syslog.conf
RCD_SCRIPTS=		puppetd puppetmasterd

PLIST_SUBST+=		DOCSDIR="${PUPPET_DOCSDIR:S,${PREFIX}/,,}"
PLIST_SUBST+=		EXAMPLESDIR="${PUPPET_EXAMPLESDIR:S,${PREFIX}/,,}"

.include "../../lang/ruby/buildlink3.mk"

DEPENDS+=		${RUBY_PKGPREFIX}-facter-[0-9]*:../../sysutils/ruby-facter

post-patch:
	${RM} ${WRKSRC}/bin/*.orig || ${TRUE}
	${SED} -e "s@/etc/puppet@${PREFIX}/etc/puppet@"		\
		${WRKSRC}/lib/puppet/configuration.rb >		\
		${WRKSRC}/lib/puppet/configuration.rb.new
	${MV} ${WRKSRC}/lib/puppet/configuration.rb.new		\
		${WRKSRC}/lib/puppet/configuration.rb

do-install:
	cd ${WRKSRC} && ${SETENV} DSTDIR=${DESTDIR}/${PREFIX}	\
		${RUBY} ${WRKSRC}/install.rb --full
	${INSTALL_DATA_DIR} ${PUPPET_DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PUPPET_DOCSDIR}
.endfor
	${INSTALL_DATA_DIR} ${PUPPET_EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${PUPPET_EXAMPLESDIR}/code
	${INSTALL_DATA} ${WRKSRC}/examples/code/* ${PUPPET_EXAMPLESDIR}/code
.for dir in ${EXAMPLEROOT_DIRS}
	${INSTALL_DATA_DIR} ${PUPPET_EXAMPLESDIR}/root/${dir}
.endfor
.for file in ${EXAMPLEROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/root/${file}		\
		${PUPPET_EXAMPLESDIR}/root/${file}
.endfor
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PUPPET_EXAMPLESDIR}

post-install:
	${RUBY} ${PREFIX}/bin/puppetmasterd				\
		--confdir=${PREFIX}/etc/puppet --rundir=/var/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> ${PUPPET_EXAMPLESDIR}/puppetmasterd.conf.sample

.include "../../mk/bsd.pkg.mk"
