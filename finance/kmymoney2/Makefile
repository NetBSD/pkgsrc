# $NetBSD: Makefile,v 1.31 2006/10/07 12:14:18 markd Exp $

DISTNAME=	kmymoney2-0.8.5
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmymoney2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE

USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
SHLIBTOOL_OVERRIDE=	# empty

.include "options.mk"

CONFIGURE_ARGS+=	--enable-mt

REPLACE_PERL+=  admin/fixuifiles

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	Fix includehints.
SUBST_FILES.hints=	kmymoney2/dialogs/*.ui kmymoney2/views/*.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
