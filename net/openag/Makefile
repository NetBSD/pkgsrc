# $NetBSD: Makefile,v 1.16 2020/05/20 06:09:07 rillig Exp $
#

DISTNAME=	OpenAG-1.1.1
PKGNAME=	openag-1.1.1
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/openags/
COMMENT=	Open Audio Galaxy client


GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	wget:run

CONFIGURE_ENV+=	WGET=wget

# mp3info/mp3info.cpp: In function 'long int get_length(mp3_file_info*, FILE*, long int)':
# mp3info/mp3info.cpp:436:52: error: array subscript has type 'char' [-Werror=char-subscripts]
#       sample_rate = samples_rates_frequencies[mpeg_v][((scan2&0x0c) >> 2)];
#                                                     ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../devel/zlib/buildlink3.mk"

INSTALLATION_DIRS+=	share/doc/OpenAG

post-install:
.for i in AUTHORS ChangeLog INSTALL NEWS README
	${INSTALL_MAN} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/OpenAG/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
