# $NetBSD: Makefile,v 1.5 1998/07/17 11:01:39 frueauf Exp $
#

DISTNAME=	mysql-3.21.33
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.digex.net/pub/database/mysql/Downloads/MySQL-3.21/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.21/

MAINTAINER=	tsarna@endicor.com

ONLY_FOR_ARCH=	i386 alpha

CONFLICTS=	mysql-3.21.31 mysql-3.21.32a

NO_CDROM=	"Restrictive license."

MYSQL_DATADIR?=	/var/mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --localstatedir=${MYSQL_DATADIR} \
		--without-perl --without-debug

USE_GMAKE=	yes
USE_PERL5=	yes

INFO_FILES=	mysql.info

pre-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

post-install:
	(cd ${WRKSRC}; ./scripts/mysql_install_db)

.include "../../mk/bsd.pkg.mk"
