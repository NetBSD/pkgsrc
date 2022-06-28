# $NetBSD: Makefile,v 1.60 2022/06/28 11:36:10 wiz Exp $

DISTNAME=	eb-4.3
PKGREVISION=	13
CATEGORIES=	textproc japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/appendix/
MASTER_SITES+=	ftp://ftp.sra.co.jp/pub/misc/eb/
DISTFILES=	${EB_DISTFILES} \
		${EB_APPENDICES}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/eb/
COMMENT=	C library for accessing EB, EBG, EBXA and EPWING CD-ROM dictionaries

EB_DISTFILES=	${DISTNAME}.tar.bz2
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
		hyogen-1.0.tar.gz \
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

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake gzip perl
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES=		${EGDIR}/eb.conf.default ${PKG_SYSCONFDIR}/eb.conf

EB_APPENDIXDIR=	${PREFIX}/share/eb/appendix
EGDIR=		${PREFIX}/share/examples/eb

# XXX Better than having unflexible/static patches.  IMO.
# -    ZLIBLIBS="-L$z_libdir -lz"
# +    ZLIBLIBS="-Wl,-R$z_libdir -L$z_libdir -lz"
SUBST_CLASSES+=		runpath
SUBST_STAGE.runpath=	pre-configure
SUBST_FILES.runpath=	configure configure.ac
SUBST_SED.runpath=	-e 's|^\(.*LIBS=['\''"]\)-L\(\$$[^[:blank:]][^[:blank:]]*\)\(.*\)$$|\1${COMPILER_RPATH_FLAG}\2 -L\2\3|'

INSTALLATION_DIRS=	share/eb/appendix

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

post-install:
.for f in ${EB_APPENDICES:Ngendai2000*}
	cd ${DESTDIR}${EB_APPENDIXDIR} && ${EXTRACTOR:M*} ${_DISTDIR}/${f}
.endfor
.for f in ${EB_APPENDICES:Mgendai2000*}
	cd ${DESTDIR}${EB_APPENDIXDIR} && ${EXTRACTOR:M*} -x ${_DISTDIR}/${f} "*/CVS*"
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/eb.conf ${DESTDIR}${EGDIR}/eb.conf.default

.include "../../mk/bsd.pkg.mk"
