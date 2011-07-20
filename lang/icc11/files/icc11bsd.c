#include <assert.h>
#include <elf.h>
#include <stddef.h>
#include <stdio.h>

FILE* my_stderr = stderr;

struct dl_phdr_info {
  Elf32_Addr        dlpi_addr;
  const char       *dlpi_name;
  const Elf32_Phdr *dlpi_phdr;
  Elf32_Half        dlpi_phnum;
};


int dl_iterate_phdr(
	int (*callback)(struct dl_phdr_info *info, size_t size, void *data),
	void *data)
{
	assert(0 && "dl_iterate_phdr is not implemented");
	return 1;
}
