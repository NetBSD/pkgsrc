# $NetBSD: Makefile,v 1.1.1.1 2004/10/23 10:40:35 jdolecek Exp $

DISTNAME=		gnucash-docs-1.8.4
PKGREVISION=		# empty
CATEGORIES=		finance
MASTER_SITES=		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Documentation for GnuCash - personal double-entry accounting program

USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
post-buildlink:
	${LN} -s /usr/include/db.h ${BUILDLINK_DIR}/include/db_185.h
.endif

.include "../../mk/bdb.buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
