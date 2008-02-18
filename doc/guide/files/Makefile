# $NetBSD: Makefile,v 1.15 2008/02/18 23:57:53 weinem Exp $

WEB_PREFIX?=	/home/mark/Desktop/cvs/htdocs

DOC=	pkgsrc

SRCS=	pkgsrc.xml
SRCS+=	binary.xml
SRCS+=	build.xml
SRCS+=	buildlink.xml
SRCS+=	bulk.xml
SRCS+=	creating.xml
SRCS+=	components.xml
SRCS+=	configuring.xml
SRCS+=	debug.xml
SRCS+=	devfaq.xml
SRCS+=	editing.xml
SRCS+=	examples.xml
SRCS+=	faq.xml
SRCS+=	files.xml
SRCS+=	fixes.xml
SRCS+=	ftp-layout.xml
SRCS+=	getting.xml
SRCS+=	infr.design.xml
SRCS+=	introduction.xml
SRCS+=	logs.xml
SRCS+=	makefile.xml
SRCS+=	options.xml
SRCS+=	pkginstall.xml
SRCS+=	platforms.xml
SRCS+=	plist.xml
SRCS+=	porting.xml
SRCS+=	regression.xml
SRCS+=	submit.xml
SRCS+=	tools.xml
SRCS+=	using.xml

# entities
SRCS+=	chapters.ent

# Make deeper TOC:
XSL_DBX_WITH_TOC_SECTION_DEPTH?= 2

# Avoid extra normalization
NO_TIDY?=	yes


all:	# doing this as depends doesn't work
	-${MAKE} html-split
	-${MAKE} html
	-${MAKE} ascii
	-${MAKE} pdf

netbsd.pdf: pdf
netbsd.txt: ascii

.include "${WEB_PREFIX}/share/mk/doc.docbook.mk"
