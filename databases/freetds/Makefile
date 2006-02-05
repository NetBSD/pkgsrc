# $NetBSD: Makefile,v 1.33 2006/02/05 23:08:30 joerg Exp $

DISTNAME=	freetds-0.63
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/stable/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-tdsver=7.0

# no thread-safe resolver functions on NetBSD
CONFIGURE_ARGS+=	--disable-threadsafe

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} ETC=${EGDIR:Q} DOCDIR=doc/${PKGBASE:Q}

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES=	${EGDIR}/freetds.conf ${PKG_SYSCONFDIR}/freetds.conf
CONF_FILES+=	${EGDIR}/locales.conf ${PKG_SYSCONFDIR}/locales.conf
CONF_FILES+=	${EGDIR}/pool.conf ${PKG_SYSCONFDIR}/pool.conf

.include "../../converters/libiconv/buildlink3.mk"

PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/.PLIST.doc

# Workaround a weird problem in the source Makefiles that prevents
# easily changing the installation directory for the documentation.
#
pre-build:
	cd ${WRKSRC}/doc/doc && ln -s ${PKGNAME_NOREV:Q} ${PKGBASE:Q}

# Dynamically generate PLIST entries for the documentation.  This target
# may need to be modified for future FreeTDS releases.
#
${WRKDIR}/.PLIST.doc:
	{ cd ${WRKSRC}/doc/doc/${PKGNAME_NOREV};			\
	  find reference userguide \( -type f -o -type l \) -print;	\
	  cd ${WRKSRC}/doc;						\
	  find images -name \*.gif -print;				\
	} | sed "s,^,share/doc/"${PKGBASE:Q}"/," | sort -u		\
	> ${.TARGET}
	{ cd ${WRKSRC}/doc/doc/${PKGNAME_NOREV};			\
	  find reference userguide -type d -print;			\
	  ${ECHO} "images";						\
	} | sed "s,^,@dirrm share/doc/"${PKGBASE:Q}"/," | sort -ur	\
	>> ${.TARGET}
	${ECHO} "@dirrm share/doc/"${PKGBASE:Q} >> ${.TARGET}

.include "../../mk/bsd.pkg.mk"
