# $NetBSD: Makefile,v 1.20 2001/03/27 03:19:49 hubertf Exp $
#

DISTNAME=		mysql-3.23.35
PKGNAME=		${DISTNAME:S/-/-server-/}nb1
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.mysql.com/MySQL-3.23/ \
			http://www.mysql.com/Downloads/MySQL-3.23/ \
			ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQL-3.23/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		MySQL, a free SQL database (server)

BUILD_DEPENDS=		autoconf-2.13:../../devel/autoconf
DEPENDS=		${DISTNAME:S/-/-client-/}:../../databases/mysql-client

EXTRACT_USING_PAX=	yes

.include "../../mk/bsd.prefs.mk"

MYSQL_DATADIR?=		/var/mysql

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${MYSQL_DATADIR} \
			--with-named-z-libs=z \
			--with-libwrap \
			--with-named-curses-libs="-lcurses -ltermcap" \
			--without-perl --without-debug --without-bench \
			--without-docs --with-low-memory

# hardwire use of included mit-pthreads on NetBSD
.if (${OPSYS} == "NetBSD")
CONFIGURE_ARGS+=	--with-mit-threads
.endif

CFLAGS+=		-Dunix

# platforms on which included mit-pthreads is usable
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-sparc NetBSD-*-m68k SunOS-*-sparc \
			NetBSD-*-powerpc

USE_PERL5=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-extract:
	@cd ${WRKSRC} && for dir in dbug heap isam merge mysys strings; do \
		${MV} $$dir/Makefile.in $$dir/Makefile.in.orig; \
		${SED} -e '/^install-exec:/s/install-pkglibLIBRARIES//' $$dir/Makefile.in.orig >$$dir/Makefile.in; \
	done

pre-configure:
	@cd ${WRKSRC}/mit-pthreads/config && ${LOCALBASE}/bin/autoconf

post-configure:
	@cd ${WRKSRC} && ${CP} config.h include/my_config.h

post-install:
	@cd ${WRKSRC}/scripts && \
		${MAKE_PROGRAM} safe_mysqld mysql_install_db && \
		${INSTALL_SCRIPT} safe_mysqld mysql_install_db ${PREFIX}/bin/
	${PREFIX}/bin/mysql_install_db --force

.include "../../mk/bsd.pkg.mk"
