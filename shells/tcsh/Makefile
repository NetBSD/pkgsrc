# $NetBSD: Makefile,v 1.92 2019/08/11 13:23:02 wiz Exp $
#
# used by shells/standalone-tcsh/Makefile
# used by shells/static-tcsh/Makefile

DISTNAME=	tcsh-6.21.00
PKGREVISION?=	0			# use ?= to allow for overrides.
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/
MASTER_SITES+=	ftp://ftp.funet.fi/pub/mirrors/ftp.astron.com/pub/tcsh/

MAINTAINER?=	pkgsrc-users@NetBSD.org	# use ?= to allow for overrides.
HOMEPAGE=	http://www.tcsh.org/
COMMENT=	Extended C-shell with many useful features
LICENSE=	original-bsd

CONFLICTS?=	static-tcsh-[0-9]*	# use ?= to allow for overrides.

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf:test perl:test

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

TEST_TARGET=	check

PKG_SHELL?=	bin/tcsh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/complete.tcsh ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/csh-mode.el ${DESTDIR}${EGDIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
