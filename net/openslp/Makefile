# $NetBSD: Makefile,v 1.16 2004/05/10 22:18:58 minskim Exp $

DISTNAME=	openslp-1.0.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openslp/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.openslp.org/
COMMENT=	Open-source implementation of the Service Location Protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
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
	${INSTALL_DATA} ${WRKSRC}/doc/rfc/* ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${HTMLDIR}
	for d in IntroductionToSLP ProgrammersGuide UsersGuide; do	\
		${INSTALL_DATA_DIR} ${HTMLDIR}/$${d};			\
		${INSTALL_DATA} ${WRKSRC}/doc/html/$${d}/* ${HTMLDIR}/$${d}; \
	done

.include "../../mk/bsd.pkg.mk"
