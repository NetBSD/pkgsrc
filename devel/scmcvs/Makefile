# $NetBSD: Makefile,v 1.10 2013/10/14 06:51:02 adam Exp $

DISTNAME=	cvs-1.12.13
CATEGORIES=	devel scm
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/source/feature/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvs.nongnu.org/
COMMENT=	Concurrent Versions System
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-external-zlib
CONFIGURE_ARGS+=	--with-rsh=ssh
CONFIGURE_ENV+=		PERL=${TOOLS_PERL5}

CHECK_INTERPRETER_SKIP=	share/cvs/contrib/*
INFO_FILES=		yes
TEXINFO_REQD+=		4.0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-case-sensitivity
.endif

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
