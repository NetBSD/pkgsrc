package histogram

import (
	"fmt"
	"io"
	"sort"
)

type Histogram struct {
	histo map[string]int
}

func New() *Histogram {
	return &Histogram{make(map[string]int)}
}

func (h *Histogram) Add(s string, n int) {
	h.histo[s] += n
}

func (h *Histogram) PrintStats(caption string, out io.Writer, limit int) {
	type entry struct {
		s     string
		count int
	}

	entries := make([]entry, len(h.histo))

	i := 0
	for s, count := range h.histo {
		entries[i] = entry{s, count}
		i++
	}

	sort.SliceStable(entries, func(i, j int) bool {
		ei := entries[i]
		ej := entries[j]
		return ej.count < ei.count || (ei.count == ej.count && ei.s < ej.s)
	})

	for i, entry := range entries {
		fmt.Fprintf(out, "%s %6d %s\n", caption, entry.count, entry.s)
		if limit > 0 && i >= limit {
			break
		}
	}
}
