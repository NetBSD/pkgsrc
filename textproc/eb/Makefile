# $NetBSD: Makefile,v 1.30 2005/05/16 01:15:33 jlam Exp $

DISTNAME=	eb-4.1.3
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/appendix/ \
		ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EB_DISTFILES} \
		${EB_LISTS} \
		${EB_APPENDICES}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/eb/
COMMENT=	C library for accessing EB, EBG, EBXA and EPWING CD-ROM dictionaries

EB_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EB_LISTS=	LIST \
		LIST-ja
EB_APPENDICES=	\
		cencro-1.0.tar.gz \
		chujiten-2.3.tar.gz \
		chujiten2-2.0.tar.gz \
		chujiten6-2.3.tar.gz \
		colloc-2.0.tar.gz \
		crownfj-2.0.tar.gz \
		crownfj2-1.0.tar.gz \
		crowngj-1.0.tar.gz \
		daihyakka-1.0.tar.gz \
		daijirin-2.0.tar.gz \
		dd75-2.0.tar.gz \
		gendai2000-1.0.tar.gz \
		genius-1.0.tar.gz \
		genius2-1.1.tar.gz \
		global-2.0.tar.gz \
		heritage-2.2.tar.gz \
		izumi-2.0.tar.gz \
		jitenban-2.4.tar.gz \
		jitenban97-2.1.tar.gz \
		kanjigen-2.0.tar.gz \
		kanjigen2-2.0.tar.gz \
		kojien-2.3.tar.gz \
		kojien2-2.0.tar.gz \
		kojien4-2.2.tar.gz \
		oxford-2.0.tar.gz \
		plus-2.0.tar.gz \
		readers-2.2.tar.gz \
		readers2-2.0.tar.gz \
		ruigigo-1.0.tar.gz \
		superdic98-1.0.tar.gz
EXTRACT_ONLY=	${EB_DISTFILES}
DIST_SUBDIR=	${PKGNAME_NOREV}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build
PKGSRC_USE_TOOLS+=	gtar

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES=		${EGDIR}/eb.conf.default ${PKG_SYSCONFDIR}/eb.conf

EB_APPENDIXDIR=	${PREFIX}/share/eb/appendix
EGDIR=		${PREFIX}/share/examples/eb

# XXX Better than having unflexible/static patches.  IMO.
# -    ZLIBLIBS="-L$z_libdir -lz"
# +    ZLIBLIBS="-Wl,-R$z_libdir -L$z_libdir -lz"
SUBST_CLASSES=		runpath
SUBST_STAGE.runpath=	post-patch
SUBST_FILES.runpath=	configure configure.ac
SUBST_SED.runpath=	-e 's|^\(.*LIBS=['\''"]\)-L\(\$$[^[:blank:]][^[:blank:]]*\)\(.*\)$$|\1-Wl,-R\2 -L\2\3|'

INSTALLATION_DIRS=	share/eb/appendix

post-extract:
	${RM} -rf ${WRKSRC}/zlib

post-install:
	for f in ${EB_LISTS}; do \
		${INSTALL_DATA} ${_DISTDIR}/$${f} ${EB_APPENDIXDIR}; \
	done
	for f in ${EB_APPENDICES}; do \
		${GTAR} -C ${EB_APPENDIXDIR} -zxmf ${_DISTDIR}/$${f}; \
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/eb.conf ${EGDIR}/eb.conf.default

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
