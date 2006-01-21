# $NetBSD: Makefile,v 1.56 2006/01/21 20:42:39 tron Exp $

DISTNAME=	rpm-2.5.4
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager

BUILD_USES_MSGFMT=	yes

CONFLICTS+=		rpm2cpio<1.0nb1

NOT_FOR_PLATFORM+=	Interix-*-* # getmntent() is nonpublic; needs porting

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

# this is needed instead of USE_PKGLOCALEDIR
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
