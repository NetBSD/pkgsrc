# $NetBSD: Makefile,v 1.55 2020/05/31 16:29:54 rillig Exp $

DISTNAME=	nvi-1.81.6
PKGREVISION=	13
CATEGORIES=	editors
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kotnet.org/~skimo/nvi/devel/
COMMENT=	Berkeley nvi with additional features
LICENSE=	modified-bsd

.include "options.mk"

CONFIGURE_DIRS=		build.unix
USE_LIBTOOL=		yes
USE_TOOLS+=		sh aclocal automake autoheader autoconf
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--program-transform-name='s,^,n,'
CONFIGURE_ENV+=		vi_cv_path_shell=${TOOLS_SH}

.if ${OPSYS} == "NetBSD"
# XXX ignore NetBSD 2.0F and later's granpt(2) and SysV pty for just now
CONFIGURE_ENV+=		vi_cv_sys5_pty=no
# XXX also ignore it on Darwin (fixes Tiger build)
.elif ${OPSYS} == "DragonFly"
CONFIGURE_ENV+=		vi_cv_include_sys_select=no
CONFIGURE_ENV+=		vi_cv_sys5_pty=no
.elif ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		vi_cv_sys5_pty=no
LDFLAGS+=		-flat_namespace
.endif

# Use of db1 is not officially supported.
BDB_ACCEPTED=		db3 db4
.include "../../mk/bdb.buildlink3.mk"
.if ${BDB_TYPE} == "db1"
CONFIGURE_ARGS+=	--with-db_type=db1
.else
CONFIGURE_ARGS+=	--with-db-prefix=${BDBBASE}
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.endif

pre-configure:
	${RUN} cd ${WRKSRC}/dist && \
	${CHMOD} 755 configure && \
	aclocal -I m4 && autoheader && autoconf

.include "../../mk/bsd.pkg.mk"
