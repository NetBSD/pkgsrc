# $NetBSD: Makefile,v 1.1.1.1 2004/10/21 14:27:37 grant Exp $

WEB_PREFIX=	${.CURDIR}/../htdocs

DOC=	pkgsrc

SRCS=	pkgsrc.xml
SRCS+=	binary.xml
SRCS+=	build.xml
SRCS+=	buildlink.xml
SRCS+=	components.xml
SRCS+=	debug.xml
SRCS+=	examples.xml
SRCS+=	faq.xml
SRCS+=	fixes.xml
SRCS+=	ftp-layout.xml
SRCS+=	getting.xml
SRCS+=	introduction.xml
SRCS+=	logs.xml
SRCS+=	options.xml
SRCS+=	platforms.xml
SRCS+=	plist.xml
SRCS+=	submit.xml
SRCS+=	using.xml

# entities
SRCS+=	chapters.ent

# Make deeper TOC:
XSL_DBX_WITH_TOC_SECTION_DEPTH?= 2 


all:	# doing this as depends doesn't work
	-${MAKE} html-split
	-${MAKE} html
	-${MAKE} ascii
	-${MAKE} pdf

netbsd.pdf: pdf
netbsd.txt: ascii

.include "${WEB_PREFIX}/share/mk/doc.docbook.mk"
