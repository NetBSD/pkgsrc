# $NetBSD: Makefile,v 1.6 2014/02/12 23:17:45 tron Exp $
#

DISTNAME=	virtuoso-opensource-6.1.6
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://sourceforge.net/projects/virtuoso/files/virtuoso/6.1.6/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://virtuoso.openlinksw.com/
COMMENT=	Universal SQL/Application server
LICENSE=	gnu-gpl-v2 # with exemptions

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-jdk2 --without-jdk3 --without-jdk4 \
			--with-iodbc=${PREFIX} \
			--with-layout=pkgsrc --localstatedir=${PREFIX}
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libsrc/zlib/zlib.pc.in

DEPENDS+=	gawk-[0-9]*:../../lang/gawk

RCD_SCRIPTS=	virtuoso
VIRTUOSO_USER=	virtuoso
VIRTUOSO_GROUP=	virtuoso
FILES_SUBST+=	VIRTUOSO_USER=${VIRTUOSO_USER} \
		VIRTUOSO_GROUP=${VIRTUOSO_GROUP}	
PKG_GROUPS=	${VIRTUOSO_GROUP}
PKG_USERS=	${VIRTUOSO_USER}:${VIRTUOSO_GROUP}

MAKE_ENV+=	ISQL=isql-vt

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/iodbc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
