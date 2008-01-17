# $NetBSD: Makefile,v 1.5 2008/01/17 11:03:02 tnn Exp $
#

DISTNAME=	cvs-1.11.22
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/source/stable/1.11.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvs.nongnu.org/
COMMENT=	Concurrent Versions System
#LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-rsh=ssh

CHECK_INTERPRETER_SKIP=	share/cvs/contrib/*

.include "options.mk"

CONFIGURE_ENV+=	PERL=${TOOLS_PERL5}

INFO_FILES=	# PLIST
USE_TOOLS+=	makeinfo
TEXINFO_REQD?=	4.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
