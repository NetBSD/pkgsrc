# $NetBSD: Makefile,v 1.3 2001/09/14 02:56:25 jlam Exp $

DISTNAME=	openslp-1.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=/etc
CONFIGURE_ARGS+=	--localstatedir=/var

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		PREFIX=${PREFIX}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		ECHO=${ECHO:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

DOCDIR=			${PREFIX}/share/doc/openslp
EGDIR=			${PREFIX}/share/examples/openslp
HTMLDIR=		${PREFIX}/share/doc/html/openslp

post-extract:
	${FIND} ${WRKSRC}/doc -name "CVS" -print | ${XARGS} ${RM} -rf

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/slpd.sh > ${WRKDIR}/slpd.sh
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/slpd.sh ${PREFIX}/etc/rc.d/slpd
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR} ${HTMLDIR}
	cd ${WRKSRC}/etc; for file in slp.conf slp.reg slp.spi; do	\
		${INSTALL_DATA} $${file} ${EGDIR};			\
	done
	cd ${WRKSRC}/doc; ${CP} -r rfc/* ${DOCDIR}
	cd ${WRKSRC}/doc; ${CP} -r html/* ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR} ${HTMLDIR}
	${CHMOD} -R a-w ${DOCDIR} ${HTMLDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
