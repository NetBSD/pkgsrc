#ifndef _ASM_X86_IO_H
#define _ASM_X86_IO_H

#ifdef SLOW_IO_BY_JUMPING
#define native_io_delay() __asm__ __volatile__("jmp 1f\n1:\tjmp 1f\n1:")
#else
#define native_io_delay() __asm__ __volatile__("outb %al,$0x80")
#endif

static inline void slow_down_io(void)
{
	native_io_delay();
#ifdef REALLY_SLOW_IO
	native_io_delay();
	native_io_delay();
	native_io_delay();
#endif
}


static inline void __outb(char value, int port) {
	asm volatile("outb" " %b" "0, %w1"
		     : : "a"(value), "Nd"(port));
}

static inline unsigned char __inb(int port)
{
	unsigned char value;
	asm volatile("inb" " %w1, %b" "0"
		     : "=a"(value) : "Nd"(port));
	return value;
}

static inline void __outw(short value, int port) {
	asm volatile("outw" " %w" "0, %w1"
		     : : "a"(value), "Nd"(port));
}

static inline unsigned short __inw(int port)
{
	unsigned short value;
	asm volatile("inw" " %w1, %w" "0"
		     : "=a"(value) : "Nd"(port));
	return value;
}

static inline void __outl(int value, int port) {
	asm volatile("outl" " %" "0, %w1"
		     : : "a"(value), "Nd"(port));
}

static inline unsigned int __inl(int port)
{
	unsigned int value;
	asm volatile("inl" " %w1, %" "0"
		     : "=a"(value) : "Nd"(port));
	return value;
}

#define outb __outb
#define outw __outw
#define outl __outl

#define inb __inb
#define inw __inw
#define inl __inl

#endif /* _ASM_X86_IO_H */
