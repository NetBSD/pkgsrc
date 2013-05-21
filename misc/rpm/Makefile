# $NetBSD: Makefile,v 1.76 2013/05/21 07:57:50 sbd Exp $

DISTNAME=	rpm-2.5.4
PKGREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	http://rpm.org/releases/historical/rpm-2.5.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager
LICENSE=	gnu-lgpl-v2 OR gnu-gpl-v2

CONFLICTS+=		rpm2cpio<1.0nb1

NOT_FOR_PLATFORM+=	Interix-*-* # getmntent() is nonpublic; needs porting

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

GMAKE_REQD+=		3.82nb1
GMAKE=			${TOOLS_GMAKE}

# this is needed in addition of USE_PKGLOCALEDIR
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${PKGLOCALEDIR}

# The rpm databases are kept under ${RPM_DB_PREFIX}/lib/rpm.
CONFIGURE_ENV+=		varprefix=${RPM_DB_PREFIX:Q}

# Needs help finding bdb.
LIBS+=			${BDB_LIBS:Q}
LDFLAGS+=		${PTHREAD_LDFLAGS}

MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man8
MAKE_FLAGS+=		ROOT=${DESTDIR}

RPMDIR=			${RPM_DB_PREFIX}/lib/rpm
FILES_SUBST+=		RPMDIR=${RPMDIR:Q}

.include "../../mk/bsd.prefs.mk"

post-configure:
	cd ${WRKSRC}/po && ${MV} cz.po cs.po

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/rpm

.if defined(RANLIB)
post-install:
	$(RANLIB) ${DESTDIR}${PREFIX}/lib/librpm.a
.endif

# The configure script doesn't detect whether libintl.so has any
# library dependencies.
#
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
