# $NetBSD: Makefile,v 1.9 2002/09/19 09:04:16 jlam Exp $

DISTNAME=	openslp-1.0.9a
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
HTMLDIR=		${PREFIX}/share/doc/html/${PKGBASE}

CONFS=			slp.conf slp.reg slp.spi
CONF_FILES=		# empty
.for FILE in ${CONFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
RCD_SCRIPTS=		slpd

post-extract:
	${FIND} ${WRKSRC} -name "CVS" -print | ${XARGS} ${RM} -rf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/etc; for file in ${CONFS}; do			\
		${INSTALL_DATA} $${file} ${EGDIR}/$${file};		\
	done
	cd ${WRKSRC}/doc; ${CP} -r rfc/* ${DOCDIR}
	cd ${WRKSRC}/doc; ${CP} -r html/* ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR} ${HTMLDIR}
	${CHMOD} -R a-w ${DOCDIR} ${HTMLDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
