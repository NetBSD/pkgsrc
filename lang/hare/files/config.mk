# install locations
PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/man
SRCDIR ?= $(PREFIX)/share/hare
STDLIB ?= $(SRCDIR)/stdlib

# variables used during build
PLATFORM ?= $(OPSYS)
ARCH ?= x86_64
HAREFLAGS =
HARECFLAGS =
QBEFLAGS =
ASFLAGS =
LDLINKFLAGS = --gc-sections -z noexecstack

# commands used by the build script
HAREC = harec
QBE = qbe
AS = as
LD = ld
SCDOC = scdoc

# build locations
HARECACHE = .cache
BINOUT = .bin

# variables that will be embedded in the binary with -D definitions
HAREPATH ?= $(STDLIB):$(SRCDIR)/third-party
VERSION=$$(./scripts/version)

# For cross-compilation, modify the variables below
AARCH64_AS=as
AARCH64_CC=cc
AARCH64_LD=ld

RISCV64_AS=as
RISCV64_CC=cc
RISCV64_LD=ld

X86_64_AS=as
X86_64_CC=cc
X86_64_LD=ld
