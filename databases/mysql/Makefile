# $NetBSD: Makefile,v 1.1 1998/06/22 10:55:21 frueauf Exp $
#

DISTNAME=	mysql-3.21.31
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.digex.net/pub/database/mysql/Downloads/MySQL-3.21/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.21/

MAINTAINER=	tsarna@endicor.com

ONLY_FOR_ARCH=	i386 alpha

NO_CDROM=	"Restrictive license."

MYSQL_DATADIR?=	/var/mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --localstatedir=${MYSQL_DATADIR} \
		--without-perl --without-debug

USE_GMAKE=	yes
USE_PERL5=	yes

INFO_FILES=	mysql.info

MAN1=		mysql.1

pre-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

post-install:
	${LDCONFIG} || ${TRUE}
	(cd ${WRKSRC}; ./scripts/mysql_install_db)

.include "../../mk/bsd.pkg.mk"
