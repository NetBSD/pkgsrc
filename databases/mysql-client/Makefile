# $NetBSD: Makefile,v 1.9 2000/08/16 01:54:09 wiz Exp $
#

DISTNAME=	mysql-3.22.32
PKGNAME=	${DISTNAME:S/-/-client-/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.mysql.com/MySQL-3.22/ \
		ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.22/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mysql.com/

NO_CDROM=	"Restrictive license."

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-perl --without-debug --without-bench \
		--without-server --with-named-curses-libs="-lcurses"

.if exists(/usr/include/readline.h)
CONFIGURE_ARGS+=--without-readline
.endif

CFLAGS+=	-Dunix

USE_PERL5=	yes
USE_LIBTOOL=	yes

INFO_FILES=	mysql.info

EXTRACT_USING_PAX=	yes

pre-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/mysql.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
