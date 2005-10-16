# $NetBSD: Makefile,v 1.13 2005/10/16 22:55:50 gdt Exp $

DISTNAME=	guile-www-1.1.1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	Guile WWW module

GNU_CONFIGURE=	YES
INFO_FILES=	guile-www.info

# Version 2.13 is available at
# http://www.glug.org/people/ttn/software/guile-www/
# It is not clear what the consequences of moving to this version are.  -gdt

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
