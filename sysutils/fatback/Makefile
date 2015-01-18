# $NetBSD: Makefile,v 1.11 2015/01/18 19:53:27 wiedi Exp $

DISTNAME=	fatback-1.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fatback/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/project/showfiles.php?group_id=46038
COMMENT=	Recover deleted files from FAT filesystems

GNU_CONFIGURE=	yes
INFO_FILES=	yes

USE_LANGUAGES=	c c++
USE_TOOLS+=	lex

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
