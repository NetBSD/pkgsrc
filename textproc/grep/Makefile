# $NetBSD: Makefile,v 1.1.1.1 2002/10/14 16:43:14 bouyer Exp $
# FreeBSD Id: Makefile,v 1.10 1999/01/27 07:41:16 fenner Exp $

DISTNAME=	grep-2.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep

USE_BUILDLINK2=         YES
BUILD_USES_MSGFMT=	YES
TEXINFO_REQD=		4.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=        --program-prefix=g

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
