# $NetBSD: Makefile,v 1.21 2001/05/28 05:36:28 jlam Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=		guile-1.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		perry@piermont.com
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgoto=no

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_READLINE=	# defined

INFO_FILES=		data-rep.info

.include "../../devel/readline/buildlink.mk"

CFLAGS+=		-I${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}

pre-configure: ${BUILDLINK_TARGETS}

.include "../../mk/bsd.pkg.mk"
