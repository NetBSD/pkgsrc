# $NetBSD: Makefile,v 1.10 1998/04/22 14:22:43 agc Exp $

DISTNAME=	tiff-v3.4beta037
PKGNAME=	tiff-3.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sgi.com/graphics/tiff/ \
		ftp://ftp.gwdg.de/pub/grafik/sgi/tiff/ \
		ftp://ftp.fu-berlin.de/unix/graphics/tiff/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tron@netbsd.org

DEPENDS+=	jpeg-6a:../../graphics/jpeg

MAN1=	fax2ps.1 fax2tiff.1 gif2tiff.1 pal2rgb.1 ppm2tiff.1 ras2tiff.1 \
	rgb2ycbcr.1 sgi2tiff.1 thumbnail.1 tiff2bw.1 tiff2ps.1 tiffcmp.1 \
	tiffcp.1 tiffdither.1 tiffdump.1 tiffgt.1 tiffinfo.1 tiffmedian.1 \
	tiffsplit.1 tiffsv.1

MAN3=	TIFFCheckTile.3 TIFFClose.3 TIFFComputeStrip.3 TIFFComputeTile.3 \
	TIFFCurrentDirectory.3 TIFFCurrentRow.3 TIFFCurrentStrip.3 \
	TIFFCurrentTile.3 TIFFDefaultStripSize.3 TIFFDefaultTileSize.3 \
	TIFFError.3 TIFFFdOpen.3 TIFFFileName.3 TIFFFileno.3 TIFFFindCODEC.3 \
	TIFFFlush.3 TIFFFlushData.3 TIFFGetField.3 TIFFGetMode.3 \
	TIFFIsByteSwapped.3 TIFFIsMSB2LSB.3 TIFFIsTiled.3 TIFFIsUpSampled.3 \
	TIFFLastDirectory.3 TIFFNumberOfStrips.3 TIFFNumberOfTiles.3 \
	TIFFOpen.3 TIFFPrintDirectory.3 TIFFRGBAImage.3 TIFFRGBAImageBegin.3 \
	TIFFRGBAImageEnd.3 TIFFRGBAImageGet.3 TIFFRGBAImageOK.3 \
	TIFFReadBufferSetup.3 TIFFReadDirectory.3 TIFFReadEncodedStrip.3 \
	TIFFReadEncodedTile.3 TIFFReadRGBAImage.3 TIFFReadRawStrip.3 \
	TIFFReadRawTile.3 TIFFReadScanline.3 TIFFReadTile.3 \
	TIFFRegisterCODEC.3 TIFFReverseBits.3 TIFFScanlineSize.3 \
	TIFFSetDirectory.3 TIFFSetErrorHandler.3 TIFFSetField.3 \
	TIFFSetSubDirectory.3 TIFFSetWarningHandler.3 TIFFStripSize.3 \
	TIFFSwabArrayOfLong.3 TIFFSwabArrayOfShort.3 TIFFSwabLong.3 \
	TIFFSwabShort.3 TIFFTileRowSize.3 TIFFTileSize.3 TIFFUnRegisterCODEC.3 \
	TIFFVGetField.3 TIFFVSetField.3 TIFFVStripSize.3 TIFFVTileSize.3 \
	TIFFWarning.3 TIFFWriteBufferSetup.3 TIFFWriteDirectory.3 \
	TIFFWriteEncodedStrip.3 TIFFWriteEncodedTile.3 TIFFWriteRawStrip.3 \
	TIFFWriteRawTile.3 TIFFWriteScanline.3 TIFFbuffer.3 TIFFcodec.3 \
	TIFFfree.3 TIFFmalloc.3 TIFFmemcmp.3 TIFFmemcpy.3 TIFFmemory.3 \
	TIFFmemset.3 TIFFquery.3 TIFFrealloc.3 TIFFsize.3 TIFFstrip.3 \
	TIFFswab.3 TIFFtile.3 libtiff.3

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--noninteractive --site ${FILESDIR}
CONFIGURE_ENV+=		PREFIX=${PREFIX}

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
