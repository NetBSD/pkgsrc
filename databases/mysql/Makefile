# $NetBSD: Makefile,v 1.17 1999/04/09 15:39:38 bad Exp $
#

DISTNAME=	mysql-3.22.21
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.digex.net/pub/database/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.22/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mysql.com/

NO_CDROM=	"Restrictive license."

MYSQL_DATADIR?=	/var/mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${MYSQL_DATADIR} \
		--with-named-z-libs='z' \
		--without-perl --without-debug --without-bench \
		--with-low-memory
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
NO_PACKAGE=	"mysql_install_db needs data dir from distribution."

post-install::
	(cd ${WRKSRC}; ./scripts/mysql_install_db)
	@${CAT} ${PKGDIR}/PLIST-server >>${PLIST_SRC}
.endif

post-install::
	${ECHO} @dirrm lib/mysql >>${PLIST_SRC}
	${ECHO} @dirrm share/mysql >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
