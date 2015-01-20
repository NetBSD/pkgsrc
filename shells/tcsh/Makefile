# $NetBSD: Makefile,v 1.78 2015/01/20 11:00:32 hauke Exp $

DISTNAME=	tcsh-6.18.01
PKGREVISION=	6
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/

MAINTAINER=	kim@NetBSD.org
HOMEPAGE=	http://www.tcsh.org/
COMMENT=	Extended C-shell with many useful features
LICENSE=	original-bsd

CONFLICTS?=	static-tcsh-[0-9]*

GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/tcsh

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOWER_OPSYS_VERSUFFIX=	${OS_VERSION:S/5./2./}
.endif

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
# XXX Should use CONFIGURE_ENV, but the configure script disregards
# $CC_FOR_GETHOST in the environment and sets it to cc.
MAKE_FLAGS+=	CC_FOR_GETHOST=${NATIVE_CC:Q}
.endif

PKG_SHELL?=	bin/tcsh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/complete.tcsh ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/csh-mode.el ${DESTDIR}${EGDIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
