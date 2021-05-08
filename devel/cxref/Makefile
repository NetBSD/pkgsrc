# $NetBSD: Makefile,v 1.16 2021/05/08 09:24:52 schmonz Exp $

DISTNAME=	cxref-1.6d
CATEGORIES=	devel lang
MASTER_SITES=	${HOMEPAGE}/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gedanken.org.uk/software/cxref/
COMMENT=	C Cross Referencing & Documenting tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	PERL=""	# Don't regenerate documentation
USE_TOOLS+=		gmake	# uses the $< variable in the GNU way
USE_TOOLS+=		lex yacc

post-extract: fix-install-target-on-case-insensitive-fs
.PHONY: fix-install-target-on-case-insensitive-fs
fix-install-target-on-case-insensitive-fs:
	cd ${WRKSRC} \
		&& ${MV} -f doc/INSTALL doc/INSTALL.txt \
		&& ${RM} -f INSTALL \
		&& ${LN} -s doc/INSTALL.txt INSTALL.txt

.include "../../mk/bsd.pkg.mk"
