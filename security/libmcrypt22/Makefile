# $NetBSD: Makefile,v 1.1.1.1 2002/04/12 18:59:36 jlam Exp $

DISTNAME=	libmcrypt-2.2.7
PKGNAME=	libmcrypt22-2.2.7
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	crypto algorithms library (version 2.2.x)

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/libmcrypt22

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-configure:
	cd ${WRKSRC};							\
	for file in lib/Makefile.in src/Makefile.in; do			\
		${SED}	-e "s|libmcrypt\.la|libmcrypt22.la|g"		\
			-e "s|libmcrypt_la|libmcrypt22_la|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
