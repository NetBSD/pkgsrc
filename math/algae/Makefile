# $NetBSD: Makefile,v 1.12 2005/01/12 15:32:00 jlam Exp $

DISTNAME=		algae-4.1.3
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=algae/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://algae.sourceforge.net/
COMMENT=		Interpreted language for numerical analysis

DEPENDS+=		gnuplot>=3.5:../../graphics/gnuplot

GNU_CONFIGURE=		# defined
USE_LANGUAGES=		fortran
USE_BUILDLINK3=		yes
USE_GNU_READLINE=	# uses history_truncate_file

INFO_FILES=		algae.info

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
