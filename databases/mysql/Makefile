# $NetBSD: Makefile,v 1.14 1999/02/04 15:47:35 frueauf Exp $
#

# note: if updated, update shlib version number in patch-aa
DISTNAME=	mysql-3.21.33b
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.digex.net/pub/database/mysql/Downloads/MySQL-3.21/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.21/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tcx.se/

CONFLICTS=	mysql-3.21.31 mysql-3.21.32a mysql-3.21.33

NO_CDROM=	"Restrictive license."

MYSQL_DATADIR?=	/var/mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${MYSQL_DATADIR} \
		--without-perl --without-debug
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib/mysql

USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes

PLIST_SRC=	${WRKSRC}/.PLIST_SRC

INFO_FILES=	mysql.info

pre-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info
	@${CP} ${PKGDIR}/PLIST-client ${PLIST_SRC}

.if (${MACHINE_ARCH} != "i386") && (${MACHINE_ARCH} != "alpha") && (${MACHINE_ARCH} != "arm32") && (${MACHINE_ARCH} != "sparc")
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
