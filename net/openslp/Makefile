# $NetBSD: Makefile,v 1.4 2001/12/14 22:30:07 jlam Exp $

DISTNAME=	openslp-1.0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
HTMLDIR=		${PREFIX}/share/doc/html/${PKGBASE}

CONF_FILES=		${EGDIR}/slp.conf ${PKG_SYSCONFDIR}/slp.conf
CONF_FILES+=		${EGDIR}/slp.reg ${PKG_SYSCONFDIR}/slp.reg
CONF_FILES+=		${EGDIR}/slp.spi ${PKG_SYSCONFDIR}/slp.spi
RCD_SCRIPTS=		slpd

post-extract:
	${FIND} ${WRKSRC} -name "CVS" -print | ${XARGS} ${RM} -rf

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/slpd.sh > ${WRKDIR}/slpd.sh

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

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
