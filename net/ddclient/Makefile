# $NetBSD: Makefile,v 1.6 2001/12/09 19:55:35 jlam Exp $

DISTNAME=	ddclient-3.6
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://burry.ca:4141/ddclient/
COMMENT=	Client to update dynamic DNS entries

USE_BUILDLINK_ONLY=	YES

DOCDIR=			${PREFIX}/share/doc/ddclient
EGDIR=			${PREFIX}/share/examples/ddclient
RCD_SCRIPTS=		ddclient
CONF_FILES_PERMS=	${EGDIR}/sample-etc_ddclient.conf		\
			${PKG_SYSCONFDIR}/ddclient.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0600
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

do-configure:
	cd ${WRKSRC}; for file in ddclient; do				\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			-e "s|@PERL5@|${PERL5}|g"			\
			$${file} > $${file}.fixed;			\
		if [ -x $${file} ]; then				\
			${CHMOD} +x $${file}.fixed;			\
		fi;							\
		${MV} -f $${file}.fixed $${file};			\
	done

do-build:	# empty

pre-install:
	@for script in ${RCD_SCRIPTS}; do				\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh	\
			> ${WRKDIR}/$${script};				\
	done

do-install:
	for script in ${RCD_SCRIPTS}; do				\
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}			\
			${PREFIX}/etc/rc.d/$${script};			\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.cisco ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-* ${EGDIR}

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
