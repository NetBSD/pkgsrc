# $NetBSD: Makefile,v 1.23 2020/12/03 23:01:27 gutteridge Exp $

DISTNAME=	gnome-common-3.18.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-common/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Generic M4 macros for GNOME development
LICENSE=	gnu-gpl-v3

# The file share/aclocal/ax_check_enable_debug.m4 conflicts
CONFLICTS=	autoconf-archive>=2014.10.15

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
