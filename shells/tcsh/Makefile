# $NetBSD: Makefile,v 1.77 2014/04/04 12:00:37 kim Exp $

DISTNAME=	tcsh-6.18.01
PKGREVISION=	5
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/

MAINTAINER=	kim@netbsd.org
HOMEPAGE=	http://www.tcsh.org/
COMMENT=	Extended C-shell with many useful features
LICENSE=	original-bsd

CONFLICTS?=	static-tcsh-[0-9]*

GNU_CONFIGURE=	yes

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

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
