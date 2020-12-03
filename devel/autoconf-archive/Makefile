# $NetBSD: Makefile,v 1.12 2020/12/03 23:01:27 gutteridge Exp $

DISTNAME=	autoconf-archive-2019.01.06
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf-archive/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.gnu.org/projects/autoconf-archive/
COMMENT=	Collection of macros for GNU Autoconf
LICENSE=	gnu-gpl-v3

# The file share/aclocal/ax_check_enable_debug.m4 conflicts
CONFLICTS=	gnome-common>=3.14.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
