# $NetBSD: Makefile,v 1.10 2001/11/30 05:45:17 jlam Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INFO_FILES=		cim.info

# Cim works by outputting C code, then executing the C compiler with
# hard-coded flags.  We need to purge these flags of any buildlink
# references.
#
SCFLAGS=	${CFLAGS:S/${BUILDLINK_DIR}/${LOCALBASE}/g}
SLDFLAGS=	${LDFLAGS:S/${BUILDLINK_DIR}/${LOCALBASE}/g}
MAKE_ENV+=	AM_MAKEFLAGS='SCFLAGS="${SCFLAGS}" SLDFLAGS="${SLDFLAGS}"'

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
