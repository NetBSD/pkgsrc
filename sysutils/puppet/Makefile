# $NetBSD: Makefile,v 1.2 2008/03/13 20:05:09 tonnerre Exp $
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
PUPPET_EGDIR=		${PREFIX}/share/examples/puppet
EXAMPLEROOT_DIRS=	bin etc etc/init.d etc/puppet
EXAMPLEROOT_FILES=	bin/sleeper etc/init.d/sleeper			\
	etc/puppet/puppetd.conf etc/puppet/fileserver.conf		\
	etc/puppet/puppetmasterd.conf etc/puppet/namespaceauth.conf	\
	etc/puppet/tagmail.conf etc/otherfile etc/configfile		\
	etc/debian-passwd etc/debian-syslog.conf
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	lib/puppet/configuration.rb
SUBST_SED.prefix=	-e "s@/etc/puppet@${PREFIX}/etc/puppet@"

INSTALLATION_DIRS=	${PUPPET_DOCSDIR} ${PUPPET_EGDIR} ${PUPPET_EGDIR}/code
INSTALLATION_DIRS+=	${PUPPET_EGDIR}/root/bin ${PUPPET_EGDIR}/root/etc
INSTALLATION_DIRS+=	${PUPPET_EGDIR}/root/etc/init.d
INSTALLATION_DIRS+=	${PUPPET_EGDIR}/root/etc/puppet

.include "../../lang/ruby/buildlink3.mk"

DEPENDS+=		${RUBY_PKGPREFIX}-facter-[0-9]*:../../sysutils/ruby-facter

do-install:
	cd ${WRKSRC} && ${SETENV} DSTDIR=${DESTDIR}/${PREFIX}	\
		${RUBY} ${WRKSRC}/install.rb --full
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PUPPET_DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/code/* ${PUPPET_EGDIR}/code
.for file in ${EXAMPLEROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/root/${file}		\
		${PUPPET_EGDIR}/root/${file}
.endfor

post-install:
	${RUBY} ${PREFIX}/bin/puppetmasterd				\
		--confdir=${PREFIX}/etc/puppet --rundir=/var/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> ${PUPPET_EGDIR}/puppetmasterd.conf.sample

.include "../../mk/bsd.pkg.mk"
