# $NetBSD: Makefile,v 1.3 2007/08/30 19:47:16 joerg Exp $
#

DISTNAME=	cvs-1.11.21
CATEGORIES=	devel scm
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/source/stable/1.11.21/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvs.nongnu.org/
COMMENT=	Concurrent Versions System

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

CHECK_INTERPRETER_SKIP=	share/cvs/contrib/*

.include "options.mk"

CONFIGURE_ENV+=	PERL=${TOOLS_PERL5:Q}

INFO_FILES=	# PLIST
USE_TOOLS+=	makeinfo
TEXINFO_REQD?=	4.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
