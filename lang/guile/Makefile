# $NetBSD: Makefile,v 1.23 2001/06/11 02:05:11 jlam Exp $
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
.include "../../mk/bsd.pkg.mk"
