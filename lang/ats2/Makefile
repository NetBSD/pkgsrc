# $NetBSD: Makefile,v 1.4 2023/01/16 04:38:04 dholland Exp $

DISTNAME=	ATS2-Postiats-0.4.2
PKGNAME=	${DISTNAME:S/ATS2-Postiats/ats2/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ats2-lang/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ats-lang.org/
COMMENT=	Functional programming language with dependent types
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/ATS2-Postiats-int-${PKGVERSION_NOREV}
GNU_CONFIGURE=	yes
USE_TOOLS+=	find gmake
# build is not job safe (... please be more specific?)
MAKE_JOBS_SAFE=	no

.include "options.mk"

.if ${PKG_OPTIONS:Memacs}
.include "../../editors/emacs/modules.mk"
# flycheck is not packaged, only build ats-mode.
pre-configure:
	cd ${WRKSRC}/utils/emacs && ${EMACS_BIN} -batch -f batch-byte-compile ats2-mode.el
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/ats2-mode
	${INSTALL_DATA} ${WRKSRC}/utils/emacs/ats2-mode.e* \
		${DESTDIR}${EMACS_LISPPREFIX}/ats2-mode
.endif

.include "../../mk/bsd.pkg.mk"
