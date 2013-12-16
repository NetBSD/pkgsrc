# $NetBSD: Makefile,v 1.81 2013/12/16 09:53:44 markd Exp $

DISTNAME=	rpm-4.11.1
CATEGORIES=	misc
MASTER_SITES=	http://rpm.org/releases/rpm-4.11.x/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager
LICENSE=	gnu-lgpl-v2 OR gnu-gpl-v2

CONFLICTS+=		rpm2cpio<1.0nb1

NOT_FOR_PLATFORM+=	Interix-*-* # getmntent() is nonpublic; needs porting

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		automake bash:run gmake msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes

GMAKE_REQD+=		3.82nb1
GMAKE=			${TOOLS_GMAKE}

REPLACE_BASH+=		scripts/*
REPLACE_PERL+=		scripts/*

# To avoid build directory references.
CONFIGURE_ENV+=		MYPATH=/sbin:/bin:/usr/sbin:/usr/bin

# this is needed in addition of USE_PKGLOCALEDIR
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--without-lua
CONFIGURE_ARGS+=	--with-external-db

BDB_ACCEPTED=		db4 db5

# The rpm databases are kept under ${RPM_DB_PREFIX}/lib/rpm.
CONFIGURE_ENV+=		varprefix=${RPM_DB_PREFIX:Q}

# Needs help finding bdb.
BUILDLINK_TRANSFORM+=	rename:-ldb:${BDB_LIBS}
LDFLAGS+=		${PTHREAD_LDFLAGS}

MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man8
MAKE_FLAGS+=		ROOT=${DESTDIR}

RPMDIR=			${RPM_DB_PREFIX}/lib/rpm
FILES_SUBST+=		RPMDIR=${RPMDIR:Q}

.include "../../mk/bsd.prefs.mk"

# The configure script doesn't detect whether libintl.so has any
# library dependencies.
#
BROKEN_GETTEXT_DETECTION=	yes

.if ${OPSYS} == "SunOS"
# for libmagic.
.include "../../sysutils/file/buildlink3.mk"
CFLAGS+=	-fno-stack-protector
BUILDLINK_TRANSFORM+=	rm:-fstack-protector
.endif


pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

SUBST_CLASSES+=		mkd
SUBST_STAGE.mkd=	post-build
SUBST_MESSAGE.mkd=	Fixing workdir tools references in macros file
SUBST_FILES.mkd=	macros
SUBST_SED.mkd+=		-e 's,${TOOLS_CMD.mkdir},${TOOLS_PATH.mkdir},'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
