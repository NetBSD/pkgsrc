# $NetBSD: Makefile,v 1.93 2006/06/24 06:12:43 jlam Exp $
#

DISTNAME=	cvs-1.11.21
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/source/stable/1.11.21/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://cvs.nongnu.org/
COMMENT=	Concurrent Versions System

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

.include "options.mk"

CONFIGURE_ENV+=	PERL=${TOOLS_PERL5:Q}

INFO_FILES=	# PLIST
USE_TOOLS+=	makeinfo
TEXINFO_REQD?=	4.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
