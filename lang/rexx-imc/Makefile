# $NetBSD: Makefile,v 1.10 2007/03/24 19:21:25 joerg Exp $
#

DISTNAME=	rexx-imc-1.76
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://users.comlab.ox.ac.uk/ian.collier/distribution/ \
		ftp://ftp.sai.msu.su/pub/unix/rexx/ \
		ftp://crydee.sai.msu.ru/zeus/unix/rexx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.comlab.ox.ac.uk/ian.collier/Rexx/
COMMENT=	Implementation of IBM's REXX scripting language

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1

CONFLICTS=	rexx-regina-[0-9]*

.include "../../mk/bsd.pkg.mk"
