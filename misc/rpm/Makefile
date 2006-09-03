# $NetBSD: Makefile,v 1.62 2006/09/03 00:56:29 wiz Exp $

DISTNAME=	rpm-2.5.4
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager

CONFLICTS+=		rpm2cpio<1.0nb1

NOT_FOR_PLATFORM+=	Interix-*-* # getmntent() is nonpublic; needs porting

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

# this is needed in addition of USE_PKGLOCALEDIR
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${PKGLOCALEDIR}

# The rpm databases are kept under ${RPM_DB_PREFIX}/lib/rpm.
CONFIGURE_ENV+=		varprefix=${RPM_DB_PREFIX:Q}

RPMDIR=			${RPM_DB_PREFIX}/lib/rpm
FILES_SUBST+=		RPMDIR=${RPMDIR:Q}

.include "../../mk/bsd.prefs.mk"

post-configure:
	cd ${WRKSRC}/po && ${MV} cz.po cs.po

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/rpm

.if defined(RANLIB)
post-install:
	$(RANLIB) ${PREFIX}/lib/librpm.a
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
