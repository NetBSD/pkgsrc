# $NetBSD: Makefile,v 1.1.1.1 1999/05/06 23:22:27 tv Exp $
#

DISTNAME=	mysql-3.22.22
PKGNAME=	${DISTNAME:S/-/-client-/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.mysql.com/pub/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.22/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mysql.com/

NO_CDROM=	"Restrictive license."

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-perl --without-debug --without-bench \
		--without-server

.if exists(/usr/include/readline.h)
CONFIGURE_ARGS+=--without-readline
.endif

CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CFLAGS+=	-Dunix

USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes

INFO_FILES=	mysql.info

pre-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
