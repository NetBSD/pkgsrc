# $NetBSD: Makefile,v 1.1.1.1 1999/05/06 23:37:00 tv Exp $
#

DISTNAME=	mysql-3.22.22
PKGNAME=	${DISTNAME:S/-/-server-/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.mysql.com/pub/mysql/Downloads/MySQL-3.22/ \
		ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.22/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mysql.com/

DEPENDS=	${DISTNAME:S/-/-client-/}:../../databases/mysql-client

NO_CDROM=	"Restrictive license."

.include "../../mk/bsd.prefs.mk"

MYSQL_DATADIR?=	/var/mysql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${MYSQL_DATADIR} \
		--with-named-z-libs=z --with-named-curses=curses \
		--without-perl --without-debug --without-bench \
		--without-docs --with-low-memory
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" CXX="${CXX}"

CFLAGS+=	-Dunix

# not yet... works on some platforms but not all
#CC=		${LOCALBASE}/bin/ptlgcc
#CXX=		${LOCALBASE}/bin/ptlg++

# platforms on which included mit-pthreads is usable
ONLY_FOR_ARCHS=	alpha arm32 i386 sparc

USE_GMAKE=	yes
USE_PERL5=	yes

post-extract:
	@cd ${WRKSRC} && for dir in dbug heap isam merge mysys strings; do \
		${MV} $$dir/Makefile.in $$dir/Makefile.in.orig; \
		${SED} -e '/^install-exec:/s/install-pkglibLIBRARIES//' $$dir/Makefile.in.orig >$$dir/Makefile.in; \
	done

post-install:
	@cd ${WRKSRC}/scripts && \
		${MAKE_PROGRAM} safe_mysqld mysql_install_db && \
		${INSTALL_SCRIPT} safe_mysqld mysql_install_db ${PREFIX}/bin/
	${PREFIX}/bin/mysql_install_db --force

.include "../../mk/bsd.pkg.mk"
