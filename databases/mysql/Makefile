# $NetBSD: Makefile,v 1.7 1998/07/20 14:49:51 tv Exp $
#

# note: if updated, update shlib version number in patch-aa
DISTNAME=	mysql-3.21.33
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.digex.net/pub/database/mysql/Downloads/MySQL-3.21/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.21/

MAINTAINER=	tsarna@endicor.com

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

CONFLICTS=	mysql-3.21.31 mysql-3.21.32a

NO_CDROM=	"Restrictive license."

MYSQL_DATADIR?=	/var/mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${MYSQL_DATADIR} \
		--without-perl --without-debug
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV=	LIBTOOL=${PREFIX}/bin/libtool

USE_GMAKE=	yes
USE_PERL5=	yes

PLIST_SRC=	${WRKSRC}/.PLIST_SRC

INFO_FILES=	mysql.info

pre-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@${CP} ${PKGDIR}/PLIST-client ${PLIST_SRC}

.if (${MACHINE_ARCH} != "i386") && (${MACHINE_ARCH} != "alpha")
CONFIGURE_ARGS+=--without-server
pre-configure:
	@${ECHO} '########## Client-only support! ##########'
	@${ECHO} 'MySQL does not support pthreads on ${MACHINE_ARCH}, so only the client'
	@${ECHO} 'support library and clients will be built.'
	@${ECHO} '##########################################'
.else
post-install:
	(cd ${WRKSRC}; ./scripts/mysql_install_db)
	@${CAT} ${PKGDIR}/PLIST-server >>${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
