# $NetBSD: Makefile,v 1.65 2006/06/07 21:11:55 minskim Exp $

DISTNAME=		a2ps-4.13b
PKGNAME=		a2ps-4.13.0.2
PKGREVISION=		11
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/} \
			ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-inf.enst.fr/~demaille/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer

DEPENDS+=		psutils>=1.17:../../print/psutils

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/a2ps-4.13
STRIP=			# empty

USE_LIBTOOL=		yes
CFLAGS.Darwin+=		-flat_namespace

USE_TOOLS+=		file:run gmake lex mktemp:run perl:run
CONFIGURE_ENV+=		file_prog=${FILE_CMD:Q}

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--with-medium=${PAPERSIZE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/a2ps
CONF_FILES=		${EGDIR}/a2ps-site.cfg ${PKG_SYSCONFDIR}/a2ps-site.cfg
CONF_FILES+=		${EGDIR}/a2ps.cfg ${PKG_SYSCONFDIR}/a2ps.cfg
INFO_FILES=		# PLIST

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
