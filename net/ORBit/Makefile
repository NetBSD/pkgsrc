# $NetBSD: Makefile,v 1.57 2001/06/19 03:55:30 jlam Exp $
#

DISTNAME=		ORBit-0.${ORBIT_MAJOR}.${ORBIT_MINOR}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/ORBit/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		high-performance CORBA ORB with support for the C language

DEPENDS+=		gindent-*:../../devel/gindent
BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake-1.4:../../devel/automake

BUILD_USES_GETTEXT_M4=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/popt/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/libIDL/ltconfig

GNU_CONFIGURE=		YES
USE_CONFIG_WRAPPER=	YES
USE_BUILDLINK_ONLY=	YES

# for DISTNAME, PKGNAME, and PLIST
ORBIT_MAJOR=		5
ORBIT_MINOR=		8
PLIST_SUBST+=		ORBIT_MAJOR=${ORBIT_MAJOR} ORBIT_MINOR=${ORBIT_MINOR}

INFO_FILES=		libIDL.info

.include "../../mk/bsd.prefs.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"

pre-configure:
	cd ${WRKSRC}/popt && ${LOCALBASE}/bin/autoreconf --include-deps --force

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	config_scripts="libIDL/libIDLConf.sh";				\
	for file in $${config_scripts}; do				\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

.include "../../mk/bsd.pkg.mk"
