# $NetBSD: Makefile,v 1.11 2004/04/25 07:40:23 snj Exp $
#

DISTNAME=		scli-0.2.12
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ibr.cs.tu-bs.de/pub/local/scli/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://www.ibr.cs.tu-bs.de/projects/scli/
COMMENT=		SNMP command line interface

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
AUTOMAKE_POST_PATTERNS+=	*.info *.info-*

CONFIGURE_ARGS+=	--with-glib-prefix=${BUILDLINK_PREFIX.glib}
USE_GNU_READLINE=	# history_list
BUILDLINK_DEPENDS.readline?=    readline>=4.0

CONFIGURE_ARGS+=	--with-xml-prefix=${BUILDLINK_PREFIX.libxml2}

INFO_FILES=		scli.info

.for _p_ in ncurses readline
CPPFLAGS+=		-I${BUILDLINK_PREFIX.${_p_}}/include
LDFLAGS+=		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.${_p_}}/lib
LDFLAGS+=		-L${BUILDLINK_PREFIX.${_p_}}/lib
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
