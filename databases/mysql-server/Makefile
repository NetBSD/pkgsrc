# $NetBSD: Makefile,v 1.6 1999/08/03 20:30:41 bad Exp $
#

DISTNAME=		mysql-3.22.22
PKGNAME=		${DISTNAME:S/-/-server-/}
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.mysql.com/pub/mysql/Downloads/MySQL-3.22/ \
			ftp://ftp.netcasting.net/pub/mysql/Downloads/MySQL-3.22/ \
			ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.22/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mysql.com/

DEPENDS=		${DISTNAME:S/-/-client-/}:../../databases/mysql-client

NO_CDROM=		"Restrictive license."

.include "../../mk/bsd.prefs.mk"

MYSQL_DATADIR?=		/var/mysql

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${MYSQL_DATADIR} \
			--with-named-z-libs=z --with-named-curses=curses \
			--without-perl --without-debug --without-bench \
			--without-docs --with-low-memory

CFLAGS+=		-Dunix

# platforms on which included mit-pthreads is usable
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-sparc NetBSD-*-m68k SunOS-*-sparc

USE_GMAKE=
USE_PERL5=

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
