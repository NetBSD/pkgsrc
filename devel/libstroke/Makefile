# $NetBSD: Makefile,v 1.30 2026/01/05 09:23:11 wiz Exp $

DISTNAME=		libstroke-0.5.1
PKGREVISION=		5
CATEGORIES=		devel
#MASTER_SITES=		http://etla.net/libstroke/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://etla.net/libstroke/
COMMENT=		Stroke translation library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
# 1.
# -----------------
# with gcc-14.3.0
# configure:1092:1: error: return type defaults to 'int' [-Wimplicit-int]
# 1092 | main(){return(0);}
#      | ^~~~
# -----------------
# 2.
# -----------------
#  ltconfig change does not make it
# +++ ltconfig    2025-10-14 07:16:53.170304613 +0900
# @@ -854,7 +854,7 @@ fi
#
#  echo $ac_n "checking if $compiler static flag $link_static_flag works... $ac_c" 1>&6
#  $rm conftest*
# -echo 'main(){return(0);}' > conftest.c
# +echo 'int main(){return(0);}' > conftest.c
# -----------------
#3.
# -----------------
# with c90
# stroke_test.c:72:1: error: C++ style comments are not allowed in ISO C90
# -----------------
FORCE_C_STD=		gnu90

CONFIGURE_ENV+=		ac_cv_path_GTK_CONFIG=no

BUILDLINK_DEPMETHOD.libX11?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
